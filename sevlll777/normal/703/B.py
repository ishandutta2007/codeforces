n, k = map(int, input().split())
C = list(map(int, input().split()))
S = list(map(int, input().split()))
G = set(S)
ans = 0
sus = sum(C)
stos = 0
for x in G:
    stos += C[x-1]
for j in S:
    ans += C[j-1] * (sus - C[j-1])
for i in range(n):
    if i+1 not in G and (i+1)%n+1 not in G:
        ans += C[i] * C[(i+1)%n]
s2 = 0
for v in G:
    s2 += C[v-1]*C[v-1]
print(ans-(stos*stos-s2)//2)