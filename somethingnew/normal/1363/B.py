for t in range(int(input())):
    lst = list(input())
    n = len(lst)
    ans0 = [0] * n
    anspost0 = [0] * n
    ans1 = [0] * n
    anspost1 = [0] * n
    ans1[0] = int(lst[0])
    anspost0[n-1] = 1 - int(lst[n-1])
    ans0[0] = 1 - int(lst[0])
    anspost1[n-1] = int(lst[n-1])
    for i in range(1, n):
        nm = int(i)
        ans0[i] = ans0[i - 1] + 1 - int(lst[i])
        ans1[i] = ans1[i - 1] + int(lst[i])
    for i in range(n - 2, -1, -1):
        anspost0[i] = anspost0[i + 1] + 1 - int(lst[i])
        anspost1[i] = anspost1[i + 1] + int(lst[i])
    minans = min(anspost1[0], anspost0[0])
    for i in range(1, n):
        minans = min(minans, ans0[i-1] + anspost1[i], ans1[i-1] + anspost0[i])
    print(minans)