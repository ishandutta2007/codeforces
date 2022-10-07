raw_input()
x = [int(_) for _ in raw_input().split()]
x.sort()
print ' '.join([str(_) for _ in x])