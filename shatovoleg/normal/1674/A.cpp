asm(R"(
.text

read_int_fmt: .asciz "%d"
print_int_fmt: .asciz "%d\n"

Scanf:
    subq $40, %rsp
    callq scanf
    addq $40, %rsp
    retq

Printf:
    subq $40, %rsp
    callq printf
    addq $40, %rsp
    retq

.global main
main:
    subq $8, %rsp
    leaq read_int_fmt(%rip), %rcx
    leaq (%rsp), %rdx
    callq Scanf
    movq (%rsp), %rax
    movq %rbx, (%rsp)
    movq %rax, %rbx

.L0:
    callq solve
    dec %rbx
    jnz .L0

    popq %rbx
    xorq %rax, %rax

    retq

solve:
    subq $24, %rsp

    leaq read_int_fmt(%rip), %rcx
    leaq (%rsp), %rdx
    callq Scanf

    leaq read_int_fmt(%rip), %rcx
    leaq 4(%rsp), %rdx
    callq Scanf

    movl 4(%rsp), %eax
    cltd
    movl (%rsp), %ecx
    idivl %ecx

    cmpl $0, %edx
    jne .L1

    movl %eax, (%rsp)

    leaq print_int_fmt(%rip), %rcx
    movq $1, %rdx
    callq Printf

    leaq print_int_fmt(%rip), %rcx
    movslq (%rsp), %rdx
    callq Printf

    jmp .end

.L1:
    leaq print_int_fmt(%rip), %rcx
    movq $0, %rdx
    callq Printf

    leaq print_int_fmt(%rip), %rcx
    movq $0, %rdx
    callq Printf

.end:
    addq $24, %rsp
    retq

)");