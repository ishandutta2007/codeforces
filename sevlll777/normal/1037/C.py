n = int(input())
a = input()
b = input()
i = 0
c = 0
while i < n:
    if i < n - 1 and a[i] != b[i] and a[i + 1] != b[i + 1] and a[i] != a[i + 1]:
        c += 1
        i += 1
    elif a[i] != b[i]:
        c += 1
    i += 1
print(c)