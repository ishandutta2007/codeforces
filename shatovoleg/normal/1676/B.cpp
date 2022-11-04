asm(R"(
.text

read_int_fmt: .asciz "%d"
read_str_fmt: .asciz "%s"
print_int_fmt: .asciz "%d\n"
.ifdef .text
print_long_long_fmt: .asciz "%lld\n"
.else
print_long_long_fmt: .asciz "%I64d\n"
.endif

NO: .asciz "NO\n"
YES: .asciz "YES\n"
KEK: .asciz "KEK\n"

.macro SAVE
    pushq %rcx
    pushq %rdx
    pushq %r8
    pushq %r9
    pushq %r10
    pushq %r11
.endm

.macro LOAD
    popq %r11
    popq %r10
    popq %r9
    popq %r8
    popq %rdx
    popq %rcx
.endm

.macro SafeCall func
    SAVE
    .ifndef .text
    movq %rcx, %r9
    movq %rdx, %r8
    movq %rsi, %rdx
    movq %rdi, %rcx
    subq $32, %rsp
    callq \func
    addq $32, %rsp
    .else
    callq \func
    .endif
    LOAD
.endm

read_int:
    leaq read_int_fmt(%rip), %rdi
    subq $8, %rsp
    leaq (%rsp), %rsi
    SafeCall scanf
    movslq (%rsp), %rax
    addq $8, %rsp
    ret

print_int:
    movq %rdi, %rsi
    leaq print_int_fmt(%rip), %rdi
    SafeCall printf
    ret

.global main
main:
    pushq %rbx
    pushq %rsi
    pushq %rdi
    callq read_int
    movq %rax, %rbx

.L0:
    callq solve
    dec %rbx
    jnz .L0

    popq %rdi
    popq %rsi
    popq %rbx
    xorq %rax, %rax

    retq

solve:
    callq read_int
    movq %rax, %r8
    xorq %r9, %r9 # ans
    xorq %r10, %r10 # idx
    movq $0xffffffff, %r11

.L1:
    callq read_int
    cmpq %r11, %rax
    jl .L2
    subq %r11, %rax
    addq %rax, %r9
    jmp .L3
.L2:
    subq %rax, %r11
    movq %r11, %rcx
    movq %rax, %r11

    movq %rcx, %rax
    imulq %r10, %rax
    addq %rax, %r9

.L3:
    inc %r10
    cmpq %r10, %r8
    jg .L1

    movq %r9, %rdi
    callq print_int

.end:
    retq

)");