s = input()
x = 0
if s.count('1') <= 1 and len(s) % 2:
    x = 1
print((len(s) + 1) // 2 - x)