for t in range(int(input())):
    n, x = map(int,input().split())
    nums = list(map(int,input().split()))
    num = 0
    while x >= 0:
        num += 1
        if not num in nums:
            x -= 1
    print(num-1)