rr = lambda: map(int, input().split(' '))

t, = rr()
for i in range(t):
    n,m = rr()
    nums = rr()
    ans = min(m, sum(nums))
    print (ans)