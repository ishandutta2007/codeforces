def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if len(set(lst)) == 1:
        print("NO")
        return 0
    print("YES")
    p1 = [lst[0], 1]
    p2 = []
    for i in range(n):
        if lst[0] != lst[i]:
            p2 = [lst[i], i + 1]
            break
    for i in range(1, n):
        if lst[i] != lst[0]:
            print(i + 1, p1[1])
        else:
            print(i + 1, p2[1])
for i in range(int(input())):
    solve()