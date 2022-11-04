asm(R"(
.text

read_int_fmt: .asciz "%d"
read_str_fmt: .asciz "%s"
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

    leaq read_str_fmt(%rip), %rcx
    leaq (%rsp), %rdx
    callq Scanf

    movzbq (%rsp), %rax
    subq $97, %rax
    xorq %rdx, %rdx

    movq $26, %rdx
    mulq %rdx
    movzbq 1(%rsp), %rdx
    subq $97, %rdx
    addq %rdx, %rax

    movzbq (%rsp), %rcx
    subq $97, %rcx
    movzbq 1(%rsp), %rdx
    subq $97, %rdx

    subq %rcx, %rax
    cmpq %rcx, %rdx
    jl .L1
    dec %rax
.L1:

    inc %rax
    leaq print_int_fmt(%rip), %rcx
    movq %rax, %rdx
    callq Printf

.end:
    addq $24, %rsp
    retq

)");