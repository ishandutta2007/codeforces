t, s, x = map(int, input().split())
if x >= t and (x - t) % s <= 1 and x != t + 1:
    print('YeS')
else:
    print('nO')