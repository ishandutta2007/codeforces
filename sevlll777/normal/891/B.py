n = int(input())
A = list(map(int, input().split()))
B = sorted(A)
for i in A:
    print(B[B.index(i) - 1], end=' ')