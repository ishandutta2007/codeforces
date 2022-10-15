##n = int(input())
n, m = map(int, input().split())
##s = input()
##A = list(map(int, input().split()))
A = dict()
for i in range(m):
    s, d = input().split()
    A[s] = d
S = input().split()
d = ''
for i in range(n):
    if len(S[i]) <= len(A[S[i]]):
        d += S[i] + ' '
    else:
        d += A[S[i]] + ' '
print(d)