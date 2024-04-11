n = int(input())
s = input()
b = 0
for i in s:
    if i == '+':
        b += 1
    else:
        b -= 1
        b = max(b, 0)
print(b)