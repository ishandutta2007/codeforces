for t in range(int(input())):
    n = int(input())
    nums = list(map(int,input().split()))
    odinr = set()
    dvar = set()
    mx = max(nums)
    sl = []
    if mx < len(nums):
        n1 = nums[:mx]
        n2 = nums[mx:]
        if sorted(n1) == list(range(1, mx+1)) and sorted(n2) == list(range(1, len(n2)+1)):
            sl += [[mx, n-mx]]
        mx = n - mx
        n1 = nums[:mx]
        n2 = nums[mx:]
        if sorted(n1) == list(range(1, mx+1)) and sorted(n2) == list(range(1, len(n2)+1)):
            sl += [[mx, n-mx]]
    if len(sl) == 2:
        if sl[0] == sl[1]:
            print(1)
            print(*sl[0])
        else:
            print(len(sl))
            for i in sl:
                print(*i)
    else:
        print(len(sl))
        for i in sl:
            print(*i)