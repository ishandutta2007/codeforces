n, k =  map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for s in a:
    if str(s).count('4') + str(s).count('7') <= k:
        ans += 1
print(ans)