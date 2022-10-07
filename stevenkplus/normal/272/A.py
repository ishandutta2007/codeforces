n = int(input())
s = sum(map(int, input().split())) % (n + 1)
cnt = sum([1 for i in range(5) if (i + 1 + s) % (n + 1) != 1])
print (cnt)