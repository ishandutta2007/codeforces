for t in range(int(input())):
    st = input()
    k = len(st) - 1
    ans = []
    for i in st:
        if i != '0':
            ans.append(i + '0' * k)
        k -= 1
    print(len(ans))
    print(*ans)