n = int(input())
A = list(map(int, input().split()))
i = max(A)
s = 0
for d in A:
    s += abs(d - i)
print(s)