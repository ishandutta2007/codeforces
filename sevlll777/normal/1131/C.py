n = int(input())
A = list(map(int, input().split()))
A.sort()
print(*A[0::2], *A[1::2][::-1])