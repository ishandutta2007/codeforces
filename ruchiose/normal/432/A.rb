first_line = gets.split(" ")
n = first_line[0].to_i
k = first_line[1].to_i
ys = gets.split(" ").collect {|x| x.to_i}
count = 0
for i in ys
  if k + i <= 5
    count += 1
  end
end
puts (count / 3)