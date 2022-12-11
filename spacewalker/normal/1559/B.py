

def inverse(c):
    return {'B':'R', 'R':'B'}[c]

def solve():
    n = int(input())
    chars = [c for c in input()]
    for i in range(1, n):
        if chars[i] == '?' and chars[i-1] != '?':
            chars[i] = inverse(chars[i-1])
    for i in range(n - 2, -1, -1):
        if chars[i] == '?' and chars[i+1] != '?':
            chars[i] = inverse(chars[i+1])
    if all(c == '?' for c in chars):
        chars = ["BR"[i%2] for i in range(n)]
    print(''.join(chars))

t = int(input())
for tc in range(t):
    solve()