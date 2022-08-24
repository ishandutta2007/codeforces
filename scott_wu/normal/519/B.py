n = input()
x = []
for i in range(3):
    x.append(sum(a for a in map(int, raw_input().split())))
print x[0] - x[1]
print x[1] - x[2]