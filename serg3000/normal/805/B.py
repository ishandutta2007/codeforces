n=int(input())
c=n // 4
if n%4 == 1:
    print('aabb' * c,'a',sep='')
if n%4 == 2:
    print('aabb' * c,'aa',sep='')
if n%4 == 3:
    print('aabb' * c,'aab',sep='')
if n%4 == 0:
    print('aabb' * c)