n, k = map(int, input().split())
s = input()
A = [0 for i in range(26)]
for i in s:
    A[ord(i) - 65] += 1
A.sort()
i = 25
##taked = 0
ans = 0
##tk = k 
##for j in range(k):
##    A[i] -= 1
##    taked += 1
##    if A[i] == 0:
##        i -= 1
##        ans += taked * taked
##        tk -= taked
##        taked = 0
##    else:
##        if j == k - 1 and tk == k:
##            ans += taked * taked
##if tk == 1 and k != 1:
##    ans += 1
while k > 0:
    k -= A[i]
    ans += A[i] * A[i]
    i -= 1
if k < 0:
    k += A[i + 1]
    ans -= A[i + 1] * A[i + 1]
    ans += k * k
    
print(ans)