n, k = map(int, input().split())
A = list(map(int, input().split()))
print(sum(sorted(A)[:k]))