for _ in range(int(input())):
    n = int(input())
    ar1 = list(map(int, input().split()))
    ar2 = []
    kek = set()
    for i in range(1, 2 * n + 1):
        if i not in ar1:
            kek.add(i)
    ans = []
    flag = 0
    for i in range(n):
        ans.append(ar1[i])
        num = 2 * n + 1
        for num in range(ar1[i] + 1, 2 * n + 1):
            if num in kek:
                break
        if num < ar1[i] or num not in kek:
            flag = 1
            break
        ans.append(num)
        kek.discard(num)
    if flag == 1:
        print(-1)
    else:
        print(*ans)