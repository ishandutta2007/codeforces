def solve():
    n = int(input())
    s = input()
    k = '-'
    tr = True
    for i in s:
        if k == '-' and i != '-':
            k = i
        if i != '-' and k != i:
            tr = False
    if tr:
        print(n)
        return 0
    ans = 0
    for i in range(n):
        if s[i] == "-" or s[i - 1] == '-':
            ans += 1
    print(ans)
for i in range(int(input())):
    solve()