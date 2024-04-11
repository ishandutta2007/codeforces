y = int(input())
for u in range(y + 1, 10001):
    s = str(u)
    if len(set(s)) == 4:
        print(u)
        exit(0)