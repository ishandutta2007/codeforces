n = int(input())
A = input().split()
h = 0
z = []
for j in A:
    if set(j) not in z:
        z.append(set(j))
        h += 1
print(h)