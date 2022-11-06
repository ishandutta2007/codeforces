def f(x):
    return sum(map(lambda x: ord(x) - ord('a') + 1, x))

n = int(input())

for i in range(n):
    s = input()
    if len(s) % 2 == 0:
        print('Alice', f(s))
    else:
        sa = max(f(s[:-1]), f(s[1:]))
        sb = min(f(s[0]), f(s[-1]))
        if sa > sb:
            print('Alice', sa - sb)
        else:
            print('Bob', sb - sa)