n = int(input())
A = list(map(int, input().split()))
if n == 1:
    if A[0] == 1:
        print(2)
    else:
        print(1)
    exit(0)
A.sort()
if A[-1] == 1:
    print('1 ' * (n - 1), 2)
    exit(0)
A[-1] = 1
A.sort()
print(*A)