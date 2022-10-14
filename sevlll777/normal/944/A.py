n, a, b = map(int, input().split())
A = [i for i in range(1, n + 1)]
ci = 0
while len(A) > 2:
    ci += 1
    B = []
    for i in range(0, len(A), 2):
        if {A[i], A[i + 1]} == {a, b}:
            print(ci)
            exit(0)
        elif A[i] in {a, b}:
            B.append(A[i])
        else:
            B.append(A[i + 1])
    A = B
print('Final!')