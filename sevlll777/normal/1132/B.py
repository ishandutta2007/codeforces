n = int(input())
A = list(map(int, input().split()))
m = int(input())
Q = list(map(int, input().split()))
A.sort(reverse=True)
z = sum(A)
for i in Q:
    print(z - A[i - 1])