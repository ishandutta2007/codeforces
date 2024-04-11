k = int(raw_input())
a = sorted(map(int , raw_input().split()))
if k == 0:
    print 0
else:
    for i in range(12)[::-1]:
        k -= a[i]
        if k <= 0:
            print 12 - i;
            break
    if k > 0:
        print -1