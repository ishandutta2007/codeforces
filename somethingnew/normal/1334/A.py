for t in range(int(input())):
    n = int(input())
    al = 0
    good = 0
    ans = "YES"
    for i in range(n):
        newall, newgood = map(int,input().split())
        if newall < al or newgood < good:
            ans = 'NO'
        if newall - al < newgood - good:
            ans = 'NO'
        al, good =  newall, newgood
    print(ans)