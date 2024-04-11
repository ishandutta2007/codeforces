b, k = map(int, input().split())
A = list(map(int, input().split()))
if b % 2 == 1:
    cnt = 0
    for i in A:
        if i % 2 == 1:
            cnt += 1
    if cnt % 2:
        print('odd')
    else:
        print('even')
else:
    if A[-1] % 2:
        print('odd')
    else:
        print('even')