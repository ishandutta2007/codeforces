def solve():
    n = int(input())
    s = input()
    n1 = 0
    for i in s:
        if i == "(":
            n1 += 1
        else:
            n1 -= 1
        n1 = max(n1, 0)
    print(n1)
for i in range(int(input())):
    solve()