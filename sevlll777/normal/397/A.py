n = int(input())
l1, r1 = map(int, input().split())
S = [0] * 101
for i in range(n - 1):
    l, r = map(int, input().split())
    for j in range(l, r):
        S[j] = 1
print(S[l1:r1].count(0))