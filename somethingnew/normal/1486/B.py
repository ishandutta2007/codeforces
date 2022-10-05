def solve():
    n = int(input())
    lst = list(map(int, input().split()))
    prefsum = 0
    for i in range(n):
        prefsum += lst[i]
        if i * (i+1)//2 >prefsum:
            print("NO")
            return 0
    print("YES")
    return 0
 
def slv(a):
    if len(a) % 2 == 1:
        return 1
    n = len(a)
    a.sort()
    return a[n//2] - a[n//2-1]+1  
def solve2():
    n = int(input())
    l2 = []
    l1 = []
    for i in range(n):
        a, b = map(int, input().split())
        l1.append(a)
        l2.append(b)
    print(slv(l1)*slv(l2))
for i in range(int(input())):
    solve2()