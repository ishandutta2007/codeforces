n = int(input())
A = list(map(int, input().split()))
M = min(A)
ahaha = 0
fl = 0
su = 0
for q in A:
    su += q
    if q != M:
        for d in range(2, int(q**0.5) + 1):
            if q % d == 0:
                ahaha = max(ahaha, -(-M-q+M*d+q//d))
                ahaha = max(ahaha, -(-M - q + M * (q // d) + q // (q // d)))
print(su - ahaha)