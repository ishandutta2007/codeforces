asm(R"(
.text
int_fmt: .asciz "%d"
str_fmt: .asciz "%s"
NO: .asciz "NO"
YES: .asciz "YES"

.global main
main:
    subq $8, %rsp
    leaq int_fmt(%rip), %rcx
    movq %rsp, %rdx
    subq $32, %rsp
    callq scanf
    addq $32, %rsp
    movq (%rsp), %rax
    movq %rbx, (%rsp)
    movq %rax, %rbx

.L0:
    callq solve
    dec %rbx
    jnz .L0

    popq %rbx

    retq

solve:
    subq $72, %rsp
    leaq str_fmt(%rip), %rcx
    movq %rsp, %rdx
    subq $32, %rsp
    callq scanf
    addq $32, %rsp

    xorq %rax, %rax
    xorq %rdi, %rdi
    xorq %rdx, %rsi
    xorq %r8, %r8

.L1:
    movb (%rsp, %r8), %al
    cmpb %al, %dil

    je .L2
    cmpq $1, %rsi
    je .L_NO
    movq $0, %rsi
    movb %al, %dil
.L2:
    inc %rsi
    inc %r8
    cmpb $0, %dil
    jne .L1
    jmp .L_YES

.L_NO:
    leaq NO(%rip), %rcx
    subq $32, %rsp
    callq puts
    addq $32, %rsp
    jmp .L_END
.L_YES:
    leaq YES(%rip), %rcx
    subq $32, %rsp
    callq puts
    addq $32, %rsp

.L_END:
    addq $72, %rsp
    retq
)");