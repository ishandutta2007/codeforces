for _ in range(int(input())):
    n = input()
    ret = (len(n) - 1) * 9
    for i in range(1, 10):
        if str(i) * len(n) <= n:
            ret += 1
    print(ret)