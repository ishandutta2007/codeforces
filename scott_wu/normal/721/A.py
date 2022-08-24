n, s = input(), input()
a = list(filter(lambda x: len(x) > 0, s.split('W')))
print(len(a))
print(' '.join(str(len(x)) for x in a))