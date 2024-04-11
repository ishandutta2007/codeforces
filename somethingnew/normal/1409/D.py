def sumnum(x):
    a = 0
    for i in x:
        a += int(i)
    return a
def plone(lst):
    n = 0
    for i in lst:
        n *= 10
        n += int(i)
    n += 1
    newlst = list(str(n))
    return newlst
def solve():
    n, s = input().split()
    s = int(s)
    lst = list(n)
    prefzero = True
    ans = []
    while len(lst):
        if prefzero and sumnum(lst) <= s:
            break
        if not prefzero and sumnum(plone(lst)) <= s:
            break
        if lst[-1] == 0:
            lst.pop()
        else:
            lst.pop()
            prefzero = False
        ans.append(0)
    if not prefzero:
        #print(lst)
        lst = plone(lst)
    k = 0
    for i in lst:
        k *= 10
        k += int(i)
    for i in ans:
        k *= 10
    print(k - int(n))
for i in range(int(input())):
    solve()