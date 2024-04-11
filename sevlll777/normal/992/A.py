n = int(input())
lol = set()
for x in list(map(int, input().split())):
    lol.add(x)
print(len(lol) - (0 in lol))