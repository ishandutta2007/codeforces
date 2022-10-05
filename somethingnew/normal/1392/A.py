def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    k = max(lst)
    lst2 = [i for i in lst if i != k]
    if len(lst2):
        print(1)
    else:
        print(n)
for i in range(int(input())):
    solve()