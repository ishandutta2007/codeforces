n = input()

x = 'I hate'
for i in range(n - 1):
    if i % 2 == 0:
        x += ' that I love'
    else:
        x += ' that I hate'
print x, 'it'