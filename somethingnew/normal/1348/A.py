predp = [2**(i+1) for i in range(31)]
for t in range(int(input())):
    mx = int(input())
    ans = 0
    for i in range(mx//2-1):
        ans += predp[i]
    for i in range(mx//2-1, mx-1):
        ans -= predp[i]
    ans += predp[mx-1]
    print(ans)