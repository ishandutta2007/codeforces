t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    s = input()
    if s == s[::-1] or k == 0:
        print(1)
    else:
        print(2)