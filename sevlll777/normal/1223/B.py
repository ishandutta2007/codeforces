for _ in range(int(input())):
    s = input()
    t = input()
    ans = 'NO'
    for c in s:
        if c in t:
            ans = 'YES'
            break
    print(ans)