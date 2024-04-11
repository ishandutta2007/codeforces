k=int(input())
if k%2==0:
    print(k//2)
    print(' '.join(['2']*(k//2)))
else:
    print(k//2)
    a=['2']*(k//2-1)
    a.append('3')
    print(' '.join(a))