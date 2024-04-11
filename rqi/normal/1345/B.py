

t = int(input())

for T in range(t):
    n = int(input())
    ans = 0
    while n >= 2:
        cur = 0
        i = 1
        while cur <= n:
            add_on = 3*i-1
            if cur+add_on <= n:
                cur+=add_on
                i+=1
            else:
                break
        n-=cur
        ans+=1
    print(ans)