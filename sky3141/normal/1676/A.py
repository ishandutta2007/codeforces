T = int(input())
for _ in range(T):
    s = input()
    a = sum(map(int, s[:3]))
    b = sum(map(int, s[3:]))
    print('yes' if a == b else 'no')