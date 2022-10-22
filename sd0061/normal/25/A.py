input()
a = map(lambda x: int(x) % 2 , raw_input().split(' '))
if sum(a) == 1:
    print a.index(1) + 1
else:
    print a.index(0) + 1