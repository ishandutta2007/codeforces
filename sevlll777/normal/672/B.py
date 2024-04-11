n = int(input())
s = input()
if n > 26:
    print(-1)
else:
    print(n - len(set(s)))