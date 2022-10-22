n, m = gets.split.map {|i| i.to_f }
if [n, m] == [1, 1]
  puts 1
  exit
end
puts (1/n + (m-1)*(n-1)/((n*m-1)*n)).to_s