T=int(raw_input())
for tt in range(T):
    n=int(raw_input())
    a=list(map(int, raw_input().split()))
    ans=list(a)
    for i in range(n):
        target=n-i
        index=-1
        for j in range(n):
            if (a[j]==target):
                index=j
        biggerIndBefore=-1
        biggerIndAfter=-1
        for j in range(n):
            if (j<index and a[j]>target):
                biggerIndBefore=j
            elif (j>index and a[j]>target and biggerIndAfter==-1):
                biggerIndAfter=j
        s=0
        if (biggerIndBefore == -1 and biggerIndAfter == -1):
            s=0
        elif (biggerIndBefore==-1):
            s+=ans[biggerIndAfter]+1
        elif (biggerIndAfter==-1):
            s+=ans[biggerIndBefore]+1
        elif a[biggerIndBefore]>a[biggerIndAfter]:
            s+=ans[biggerIndAfter]+1
        else: 
            s+=ans[biggerIndBefore]+1
        ans[index]=s
    for i in range(n):
        print ans[i],
    print