a = int(input())
for p in range(2, a):
    if a % p == 0:
        print(str(p)+str(a//p))
        exit(0)