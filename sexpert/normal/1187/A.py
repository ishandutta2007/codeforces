T = int(input())
for _ in range(T):
    [n, s, t] = map(int, input().split())
    print(max(s, t) - (s + t - n) + 1)