mima = -10 ** 9
mami = -10 ** 9
asan = []
for _ in range(int(input())):
    c, x, y = input().split()
    x, y = int(x), int(y)
    x, y = min(x, y), max(x, y)
    if c == '+':
        mima = max(mima, x)
        mami = max(mami, y)
    else:
        if x >= mima and y >= mami:
            asan.append('yes')
        else:
            asan.append('no')
print('\n'.join(asan))